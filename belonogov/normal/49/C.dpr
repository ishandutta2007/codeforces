var
  i, n: longint;

begin
 read(n);
  if n mod 2 = 0 then
  for i := 1 to (n div 2) do
    write((i * 2), ' ',  (i * 2 - 1), ' ');

  if n mod 2 = 1 then
  begin
    write(1, ' ');
    for i := 1 to (n div 2) do
      write((i * 2 + 1), ' ',  (i * 2), ' ');
  end;

end.