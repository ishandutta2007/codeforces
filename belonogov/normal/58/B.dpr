var
  n, i: longint;

begin
   read(n);
  while n <> 1 do
  begin
    write(n, ' ');
    i := 2;
    while n mod i <> 0 do
      inc(i);
    n := n div i;
  end;
  write(1);

end.