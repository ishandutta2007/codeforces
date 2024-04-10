var n : longint;
begin
   readln (n);
   if n mod 3 > 1 then inc(n);
   write(n div 36,' ', (n mod 36)div 3)
end.