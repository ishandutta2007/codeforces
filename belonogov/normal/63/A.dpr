var
  a: array[1..100, 1..2] of string;
  n, i, j: longint;
  s: string;

begin
  readln(n);
  for i := 1 to n do
  begin
    readln(s);
    j := 1;
    while (j <= length(s)) and (s[j] <> ' ') do
      inc(j);

    a[i, 1] := copy(s, 1, j - 1);
    a[i, 2] := copy(s, j + 1, length(s) - j);
  end;

  for i := 1 to n do
    if a[i, 2] = 'rat' then writeln(a[i, 1]);

  for i := 1 to n do
    if (a[i, 2] = 'woman') or (a[i, 2] = 'child') then writeln(a[i, 1]);

  for i := 1 to n do
    if a[i, 2] = 'man' then writeln(a[i, 1]);

  for i := 1 to n do
    if a[i, 2] = 'captain' then writeln(a[i, 1]);


end.