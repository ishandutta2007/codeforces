{$O-}
var
  a: array[1..1000, 1..4] of longint;
  n, i, j, j1, sum: longint;
  check: boolean;
  s: string;

begin
  readln(n);
  for i := 1 to n do
  begin
    readln(s);
    a[i, 1] := ord(s[1]) - ord('0');
    a[i, 2] := ord(s[2]) - ord('0');
    readln(s);
    a[i, 4] := ord(s[1]) - ord('0');
    a[i, 3] := ord(s[2]) - ord('0');
    readln(s);
  end;

  sum := 0;
  for i := 1 to n do
  begin
    check := true;
    for j := 1 to i - 1 do
      for j1 := 0 to 3 do
        if (a[j, 1] = a[i, (1 + j1 - 1) mod 4 + 1]) and (a[j, 2] = a[i, (2 + j1 - 1) mod 4 + 1]) and
           (a[j, 3] = a[i, (3 + j1 - 1) mod 4 + 1]) and (a[j, 4] = a[i, (4 + j1 - 1) mod 4 + 1]) then
          check := false;
    if check then inc(sum);

  end;

  writeln(sum);



end.