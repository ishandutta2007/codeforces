var
  i, n: longint;

begin
  read(n);
  if n = 2 then write(-1)
  else
  begin
    writeln(997 * 2);
    writeln(997 * 3);
    for i := 3 to n do
      writeln(6 * i);
  end;
  
end.