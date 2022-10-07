var
  a, b, c: array[1..100000] of longint;
  check: array[1..100000] of boolean;
  n, i, sum, min: longint; 

begin
  read(n);
  for i := 1 to n do
    read(a[i]);

  for i := 1 to n do
    read(b[i]);

  c[1] := 0;
  for i := 2 to n do
    c[i] := c[i - 1] + a[i - 1] - b[i - 1];

  min := c[1];
  for i := 1 to n do
    if  min > c[i] then min := c[i];

  for i := 1 to n do
    if min - c[i] >= 0 then check[i] := true;
  {//////////////////}

  c[n] := 0;
  for i := n - 1 downto 1 do
    c[i] := c[i + 1] + a[i + 1] - b[i];

  min := c[n];
  for i := 1 to n do
    if  min > c[i] then min := c[i];

  for i := 1 to n do
    if min - c[i] >= 0 then check[i] := true;
  {////////////////////}

  sum := 0;
  for i := 1 to n do
    if check[i] then inc(sum);

  writeln(sum);
  for i := 1 to n do
    if check[i] then write(i, ' ');

end.