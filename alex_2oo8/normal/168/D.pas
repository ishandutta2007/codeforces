program problem4;

var n, l, k, i, j, ci, li: longInt;
    arr: array[ 0..1, 0..200, -200..200 ] of real;
    p, a: array[1..200] of longInt;
    ans: real;

begin
  readln( n, l, k );
  for i := 1 to n do
    read( p[i] );
  readln();
  for i := 1 to n do
    read( a[i] );

  ci := 0;
  li := 1;
  for i := -200 to 200 do
    arr[ci][0][i] := 0.0;
  arr[ci][0][k] := 1.0;

  for i := 1 to n do
  begin
    ci := 1 - ci;
    li := 1 - li;
    for j := 0 to i do
    begin
      for k := -200 to 199 do
      begin
        arr[ci][j][k] := 0.0;
        if ( j < i ) then
          arr[ci][j][k] := arr[ci][j][k] + ( arr[li][j][k] * (100-p[i]) / 100 );
        if ( j > 0 ) and ( (k-a[i]) >= -200 ) then
          arr[ci][j][k] := arr[ci][j][k] + ( arr[li][j-1][ k - a[i] ] * p[i] / 100 );
      end;

      arr[ci][j][200] := 0.0;
      if ( j < i ) then
        arr[ci][j][200] := arr[ci][j][200] + ( arr[li][j][200] * (100-p[i]) / 100 );
      if ( j > 0 ) then
        for k := 200 downTo (200-a[i]) do
          arr[ci][j][200] := arr[ci][j][200] + ( arr[li][j-1][k] * p[i] / 100 );
    end;
  end;

  ans := 0.0;
  for j := l to n do
    for k := 0 to 200 do
      ans := ans + arr[ci][j][k];

  writeln( ans:0:12 );
end.