program problem3;
type rec = record
             k, c: longWord;
           end;
     tArr = array[1..100] of rec;

procedure qsort( var arr: tArr; l, r: longWord );
var i, j, med: longWord;
    t: rec;
begin
  if ( l < r ) then
  begin
    med := arr[ (l+r) div 2 ].c;
    i := l;
    j := r;
    while ( i <= j ) do
    begin
      while ( arr[i].c < med ) do
        inc( i );
      while ( arr[j].c > med ) do
        dec ( j );

      if ( i <= j ) then
      begin
        t := arr[i];
        arr[i] := arr[j];
        arr[j] := t;

        inc( i );
        dec( j );
      end;
    end;

    qsort( arr, l, j );
    qsort( arr, i, r );
  end;
end;

var arr: tArr;
    n, t, i, k, a: longWord;
    p: array[0..101] of qWord;
    ans: qWord;

begin
  readln( n );
  for i := 1 to n do
    readln( arr[i].k, arr[i].c );
  readln( t );
  p[0] := 0;
  for i := 1 to t do
    read( p[i] );
  for i := t downTo 1 do
    p[i] := p[i] - p[i-1];
  p[t+1] := trunc(1.0e+18);
  k := 1;

  qsort( arr, 1, n );

  a := 1;
  ans := 0;

  while ( a <= n ) and ( arr[a].k > 0 ) do
  begin
    if ( arr[a].k > p[k] ) then
    begin
      ans := ans + ( qWord( k ) * p[k] * arr[a].c );
      arr[a].k := arr[a].k - p[k];
      inc( k );
    end
    else
    begin
      ans := ans + ( qWord( k ) * arr[a].k * arr[a].c );
      p[k] := p[k] - arr[a].k;
      arr[a].k := 0;
      inc( a );
      if ( p[k] = 0 ) then
        inc( k );
    end;
  end;

  writeln( ans );
end.