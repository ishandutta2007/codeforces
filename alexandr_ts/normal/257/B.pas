var n,m:longint;
begin
 read(n,m);
 if n<m then
   write(m-1,' ',n)
 else
   write(n-1,' ',m);
end.