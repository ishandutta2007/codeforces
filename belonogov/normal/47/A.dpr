var
  q: boolean;
  i, n: longint;

begin
  read(n);
  q := false;
  for i :=  1 to 500 do
    if ((i * (i - 1)) div 2) = n then q := true;

  if q then writeln('YES') else writeln('NO')



end.