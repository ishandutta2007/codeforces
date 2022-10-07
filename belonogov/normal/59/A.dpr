var
  s: string;
  litl, litr, lit, big, bigl, bigr, i: longint;

begin
  readln(s);
  litl := ord('a');
  litr := ord('z');
  bigl := ord('A');
  bigr := ord('Z');
  lit := 0;
  big := 0;
  for i := 1 to length(s) do
    if (ord(s[i]) <= litr) and (ord(s[i]) >= litl) then
      inc(lit)
    else
      inc(big);

  if lit >= big then
  for i := 1 to length(s) do
    if (ord(s[i]) <= litr) and (ord(s[i]) >= litl) then
      write(s[i])
    else
      write(chr(ord(s[i]) - ord('A') + ord('a')));

  if lit < big then
  for i := 1 to length(s) do
    if (ord(s[i]) <= bigr) and (ord(s[i]) >= bigl) then
      write(s[i])
    else
      write(chr(ord(s[i]) - ord('a') + ord('A')));


end.