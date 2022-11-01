var a,b,i,n,j:longint;
 begin
  read (n,a,b);
  for i:=1 to n do
   if (i-1>=a) and (n-i<=b) then inc (j);
 write (j);
end.