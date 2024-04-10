var
  n, k, i: longint;


begin
  read(n);
  k := 1;
  for i := 2 to n do
    k := (k * 3) mod 1000003;
  writeln(k);  



end.