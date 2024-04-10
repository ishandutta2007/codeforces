program problem7;

var n, i, j, k: longWord;
    x, p: array[1..500] of longWord;

begin
  n := 500;
  x[1] := 0;
  p[1] := 1000000;
  x[2] := 35000;
  p[2] := n;
  x[n] := 1000000;
  p[n] := 1000000;

  for i := 3 to (n-1) do
  begin
    p[i] := n - i;
    x[i] := x[i-1] + p[i-1] + p[i];
  end;

  writeln( n );
  for i := 1 to n do
    writeln( x[i], ' ', p[i] );
end.