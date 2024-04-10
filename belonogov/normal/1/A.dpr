var
  a, n, m: int64;

begin
  read(n, m, a);
  write(((n + a - 1) div a) * ((m + a - 1) div a));

end.