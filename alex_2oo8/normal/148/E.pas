program problem5;
uses math;

type tArr = array[0..100] of longWord;

function calc( const a: tArr; cnt: longWord ): tArr;
var l, i, j, k, li, ci: longWord;
    arr: array[ 0..1, 0..101, 0..101 ] of longWord;
    res: tArr;
begin
  res[0] := 0;
  ci := 0;
  li := 1;

  for i := 1 to (cnt+1) do
    for j := (i-1) to (cnt+1) do
      arr[ci][i][j] := 0;

  for k := 1 to cnt do
  begin
    ci := 1 - ci;
    li := 1 - li;

    for l := k to cnt do
    begin
      for i := 1 to (cnt-l+1) do
      begin
        j := i + l - 1;
        arr[ci][i][j] := max( ( arr[li][i][j-1] + a[j] ), ( arr[li][i+1][j] + a[i] ) );
      end;
    end;

    res[k] := arr[ci][1][cnt];
  end;

  calc := res;
end;

var n, m, i, j, k, ci, li, cnt: longWord;
    a, b: tArr;
    arr: array[ 0..1, 0..10000 ] of longWord;

begin
  readln( n, m );

  ci := 0;
  li := 1;
  arr[li][0] := 0;
  for i := 0 to m do
    arr[ci][i] := 0;

  for i := 1 to n do
  begin
    ci := 1 - ci;
    li := 1 - li;

    read( cnt );
    for j := 1 to cnt do
      read( a[j] );
    readln();
    b := calc( a, cnt );

    for j := 1 to m do
    begin
      arr[ci][j] := 0;
      for k := 0 to min( j, cnt ) do
        arr[ci][j] := max( arr[ci][j], ( arr[li][j-k] + b[k] ) );
    end;
  end;

  writeln( arr[ci][m] );
end.