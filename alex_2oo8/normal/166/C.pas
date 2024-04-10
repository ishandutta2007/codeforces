program problem3;
type tArr = array[1..500] of longWord;

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

var n, x, ans, i: longWord;
    arr: tArr;
    check: boolean;
    a: integer;

begin
  ans := 0;
  check := false;

  readln( n, x );
  for i := 1 to n do
  begin
    read( arr[i] );
    if ( arr[i] = x ) then
      check := true;
  end;
  if not check then
  begin
    inc( n );
    arr[n] := x;
    inc( ans );
  end;

  qsort( arr, 1, n );

  i := 0;
  if arr[ (n+1) div 2 ] > x then
    a := -1
  else
    a := 0;
  while ( arr[ ( (n+1+i) div 2 ) + i*a ] <> x ) do
  begin
    inc( i );
    inc( ans );
  end;

  writeln( ans );
end.