var
  s1, s2: string;
  x, i: longint;
begin
  readln(s1);
  readln(s2);
  x := length(s1);
  for i := 1 to x do
    if s1[i] <> s2[i] then write('1') else write('0');

end.