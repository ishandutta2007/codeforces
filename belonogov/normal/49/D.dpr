var
  i, n, k, z: longint;
  s, q: string;

begin
  readln(q);
  readln(s);
  n := length(s);
  z := 0;
  for i := 1 to n do
    if (ord(s[i]) - ord('1') + 1)  <> i mod 2  then inc(z);

  if z < n - z then
    writeln(z)
  else
    writeln(n - z);

end.