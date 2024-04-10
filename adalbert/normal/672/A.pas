var n,i:longint;
s,st:ansistring;
begin
read(n);
for i:=1 to 1000 do
begin
str(i,s);
insert(s,st,length(st)+1);
end;
writeln(st[n]);
end.