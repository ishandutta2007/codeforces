program problem4;
uses math;

var ans, n, a, b: longWord;
    arr, ans_arr: array[0..9] of longWord;
    hp: array[1..10] of longWord;

procedure calc( k: longWord );
var sum, i, j: longInt;
begin
  if ( k = (n-1) ) then
  begin
    arr[k] := max( ( ( max( hp[n], (hp[k-1]-arr[k-1]*a-arr[k-2]*b) ) + b ) div b ), ( ( hp[k] + a ) div a ) );
    sum := 0;
    for i := 2 to (n-1) do
      inc( sum, arr[i] );

    if ( sum < ans ) then
    begin
      ans := sum;
      ans_arr := arr;
    end;
  end
  else
  begin
    for i := max( 0, ( (hp[k-1]-(arr[k-1]*a)-(arr[k-2]*b)+b) div b ) ) to max( ( ( (hp[k-1]-(arr[k-1]*a)-(arr[k-2]*b) ) + b ) div b ), ( ( hp[k] + a ) div a ) ) do
    begin
      arr[k] := i;
      calc( k + 1 );
    end;
  end;
end;

var i, j: longWord;

begin
  ans := 999999999;
  arr[0] := 0;
  arr[1] := 0;

  readln( n, a, b );
  for i := 1 to n do
    read( hp[i] );

  calc( 2 );

  writeln( ans );
  for i := 2 to (n-1) do
    for j := 1 to ans_arr[i] do
      write( i, ' ' );
end.