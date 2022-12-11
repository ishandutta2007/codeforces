var a:array[1..1000,1..1000]of longint;
    b,c:array[1..1000]of longint;
    i,x,y,s,s1,n,m:longint;
begin
 readln(n,m);
 for i:=1 to n do
 begin
  readln(x,y);
  inc(a[x,y]);
  inc(c[y]);
 end;
 for i:=1 to m do
 begin
  readln(x,y);
  dec(a[x,y]);
  if a[x,y]>=0 then begin inc(s);dec(c[y]);end else inc(b[y]);
 end;
 for i:=1 to 1000 do
  if b[i]>=c[i] then s1:=s1+c[i] else s1:=s1+b[i];
 writeln(s+s1,' ',s);
end.