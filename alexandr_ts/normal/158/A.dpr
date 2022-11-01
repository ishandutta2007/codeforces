var a:array[1..100] of integer;
    n, k, i, quantity:integer;
begin
 read(n, k);
 for i := 1 to n do
  read(a[i]);
 for i := 1 to n do
  if (a[i] >= a[k]) and(a[i] > 0) then
   inc(quantity);
 write(quantity);
end.