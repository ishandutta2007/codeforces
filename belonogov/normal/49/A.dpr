var
  s: string;
  i: longint;
  q: char;

begin
  readln(s);
  i := 1;
  while  s[i] <> '?' do
    inc(i);

  dec(i);
  while s[i] = ' ' do
    dec(i);
  q := s[i];
  if (q = 'a') or (q = 'e') or (q = 'i') or (q = 'o') or (q = 'u') or (q = 'y') or
     (q = 'A') or (q = 'E') or (q = 'I') or (q = 'O') or (q = 'U') or (q = 'Y') then
     writeln('YES')
  else
    writeln('NO');

end.