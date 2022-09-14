var x,y,a,b,r,l,c:longint;

function nod (p,q:longint) : longint;
var t:longint;
begin
if p<q then
        begin
         t:=p;
         p:=q;
         q:=t;
        end;
if p mod q = 0 then t := q
          else
            t:=nod (p mod q,q);
nod:=t;
end;



begin
read (x,y,a,b);
c:=x*y div nod (x,y);
l:=(a-1) div c;
r:=b div c;
write (r-l);
end.