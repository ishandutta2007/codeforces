var
  s: string;
  i: longint;
  check: boolean;
begin
  readln(s);
  i := 1;
  check := true;
  while (s[i] <> 'h') and (i < length(s)) do
    inc(i);

  if s[i] <> 'h' then check := false;
  inc(i); 
  while (s[i] <> 'e') and (i < length(s)) do
    inc(i);

  if s[i] <> 'e' then check := false;
  inc(i);
  while (s[i] <> 'l') and (i < length(s)) do
    inc(i);

  if s[i] <> 'l' then check := false;
  inc(i);
  while (s[i] <> 'l') and (i < length(s)) do
    inc(i);

  if s[i] <> 'l' then check := false;
  inc(i);

  while (s[i] <> 'o') and (i < length(s)) do
    inc(i);

  if s[i] <> 'o' then check := false;

   if check then write('YES')
   else
     write('NO');
end.