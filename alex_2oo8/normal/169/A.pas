program problem1;
type tArr = array[1..2000] of longWord;

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

var n, a, b, i: longWord;
    h: tArr;

begin
  readln( n, a, b );

  for i := 1 to n do
    read( h[i] );

  qsort( h, 1, n );

  writeln( h[ n - a + 1 ] - h[ n - a ] );
end.