var n,i,v,nv:longint;
c:char;
a:array['a'..'z'] of longint;
s,st:ansistring;
begin
readln(n);
readln(st);
for i:=1 to n do inc(a[st[i]]);
for c:='a' to 'z' do
    if a[c]=0 then inc(nv) else
     v:=v+a[c]-1;

if v>nv then writeln(-1) else writeln(v);
end.