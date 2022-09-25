program problem2;
type tArr = array[1..100000] of byte;

procedure qsort( var arr: tArr; l, r: longWord );
var mid, i, j, t: longWord;
begin
  if ( r > l ) then
  begin
    mid := arr[ (l+r) div 2 ];
    i := l;
    j := r;
    while ( i <= j ) do
    begin
      while ( arr[i] < mid ) do
        inc( i );
      while ( arr[j] > mid ) do
        dec( j );

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

var a, s: tArr;
    n, m, i, j: longWord;
    chr: string[1];

begin
  n := 0;
  read( chr );
  while ( chr <> '' ) do
  begin
    inc( n );
    a[n] := ord( chr[1] ) - ord( '0' );
    read( chr );
  end;
  readln;

  m := 0;
  read( chr );
  while ( chr <> '' ) do
  begin
    inc( m );
    s[m] := ord( chr[1] ) - ord( '0' );
    read( chr );
  end;

  qsort( s, 1, m );

  j := m;
  for i := 1 to n do
  begin
    if ( a[i] < s[j] ) then
    begin
      a[i] := s[j];
      dec(j);
      if ( j = 0 ) then
        break;
    end;
  end;

  for i := 1 to n do
    write( a[i] );
end.