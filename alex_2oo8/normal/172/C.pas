program problem3;
type rec = record
             t, x: longWord;
             w: qWord;
           end;
     tArr = array[ 0..100000 ] of longWord;

var arr: array[ 1..100000 ] of rec;

procedure qsort( var a: tArr; l, r: longWord );
var mid, i, j, t: longWord;
begin
  if ( r > l ) then
  begin
    mid := arr[ a[ (l+r) div 2 ] ].x;
    i := l;
    j := r;
    while ( i <= j ) do
    begin
      while ( arr[ a[i] ].x < mid ) do
        inc( i );
      while ( arr[ a[j] ].x > mid ) do
        dec( j );

      if ( i <= j ) then
      begin
        t := a[i];
        a[i] := a[j];
        a[j] := t;

        inc( i );
        dec( j );
      end;
    end;

    qsort( a, l, j );
    qsort( a, i, r );
  end;
end;

var n, m, i, u, s, x, k: longWord;
    t: qWord;
    p: tArr;

begin
  readln( n, m );

  for i := 1 to n do
    readln( arr[i].t, arr[i].x );

  t := 0;
  u := 0;

  while ( u < n ) do
  begin
    if ( n - u ) >= m then
    begin
      for i := (u+1) to (u+m) do
        p[ i - u ] := i;
      p[0] := m;
      u := u + m;
    end
    else
    begin
      for i := (u+1) to n do
        p[ i - u ] := i;
      p[0] := n - u;
      u := n;
    end;
    if ( t < arr[ p[ p[0] ] ].t ) then
      t := arr[ p[ p[0] ] ].t;

    s := 0;
    x := 0;

    qsort( p, 1, p[0] );

    while ( s < p[0] ) do
    begin
      k := s;
      t := t + ( arr[ p[s+1] ].x - x );
      x := arr[ p[s+1] ].x;
      inc( s );
      arr[ p[s] ].w := t;
      while ( s < p[0] ) and ( arr[ p[s+1] ].x = arr[ p[s] ].x ) do
      begin
        inc( s );
        arr[ p[s] ].w := t;
      end;
      t := t + 1 + ( (s-k) div 2 );
    end;

    t := t + x;
  end;

  for i := 1 to n do
    write( arr[i].w, ' ' );
end.