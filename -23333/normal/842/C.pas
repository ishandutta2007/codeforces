uses math;
type re=record
  a,b,c:longint;
end;
var
  i,j,m,n,x,y,l:longint;
  f:array[1..1000000]of boolean;
  a:array[1..1000000]of re;
  v,b,c,head:array[1..1000000]of longint;
function gcd(x,y:longint):longint;
begin
  if x mod y=0 then exit(y) else exit(gcd(y,x mod y));
end;
procedure dfs(x,y,z:longint);
var
  i,j,m,n,r,maxn,u,vv:longint;
begin
  f[x]:=false;
  maxn:=z;
  r:=gcd(z,v[x]);
//  r:=-1;
  for i:=1 to trunc(sqrt(v[x])) do
  begin
    if v[x] mod i=0 then
    begin
      inc(b[i]);
      if b[i]>=y-1 then maxn:=max(maxn,i);
//      if b[i]=y then r:=max(r,i);
    end;
    if (v[x] mod i=0) and (i*i<>v[x]) then
    begin
      inc(b[v[x] div i]);
      if b[v[x] div i]>=y-1 then maxn:=max(maxn,v[x] div i);
 //     if b[v[x] div i]=y then r:=max(r,v[x] div i)
    end;
  end;
  u:=head[x];
  c[x]:=maxn;
  while u<>0 do
  begin
    vv:=a[u].b;
    if f[vv] then dfs(vv,y+1,r);
    u:=a[u].a;
  end;
  for i:=1 to trunc(sqrt(v[x])) do
  begin
    if v[x] mod i=0 then
      dec(b[i]);
    if (v[x] mod i=0) and (i*i<>v[x]) then
      dec(b[v[x] div i]);
    end;
end;
procedure arr(x,y:longint);
begin
  inc(l);
  a[l].a:=head[x];
  a[l].b:=y;
  head[x]:=l;
end;
begin
  readln(n);
  for i:=1 to n do
    read(v[i]);
  for i:=1 to n-1 do
  begin
    read(x,y);
    arr(x,y); arr(y,x);
  end;
  fillchar(f,sizeof(f),true);
  dfs(1,1,v[1]);
  for i:=1 to n do
    write(c[i],' ');
end.