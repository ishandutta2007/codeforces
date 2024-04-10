{$O-} {$R+}
var
  x: array[1..50, 1..50] of longint;
  min, sum, a, b, n, m, i, j, i1, j1: longint;

begin
  read(n, m);
  for i := 1 to n do
    for j := 1 to m do
      read(x[i, j]);
  read(a, b);
  min := a * b;
  for i := 1 to n - a + 1 do
    for j := 1 to m - b + 1 do
    begin
      sum := 0;
      for i1 := i to (a + i - 1) do
        for j1 := j to (b + j - 1) do
          if x[i1, j1] = 1 then inc(sum);
      if min > sum then min := sum;
    end;
  {}
  for i := 1 to m - a + 1 do
    for j := 1 to n - b + 1 do
    begin
      sum := 0;
      for i1 := i to (a + i - 1) do
        for j1 := j to (b + j - 1) do
          if x[j1, i1] = 1 then inc(sum);
      if min > sum then min := sum;
    end;

  writeln(min);

end.