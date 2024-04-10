var n,a,s,m:int64;
    i:longint;
    b:array[0..100000] of int64;
function ab (k:int64): int64;
begin
if k=0 then ab:=0
       else if k mod 2=0 then ab:=ab(k div 2)
                         else ab:=ab(k div 2)+1;
end;

begin
read (n);
for i:=1 to n do
        begin
         read (a);
         s:=ab(a);
         inc(b[s])
        end;
m:=0;
for i:=0 to 100000 do m:=m+b[i]*(b[i]-1)div 2 ;
write (m);
end.