Var d:array[1..100] of integer;
    n,s,t,k,i:integer;
    p1,p2:longint;
begin
read (n);
for i:=1 to n do read (d[i]);
read (s,t);
if s>=t then
        begin
         k:=s;
         s:=t;
         t:=k;
        end;

p1:=0;
p2:=0;
for i:=s to t-1 do p1:=p1+d[i];
for i:=t to n do p2:=p2+d[i];
for i:=1 to s-1 do p2:=p2+d[i];
if p1>p2 then write (p2)
         else write (p1);
end.