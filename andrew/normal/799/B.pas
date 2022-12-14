var
 a,b,c,l,r,v:array[1..200000]of longint;
 cst,st,stn:array[1..3,1..200000]of longint;
 c1,c2,x,ans,i,j,n,m,k,sc,sc1,ch1,ch2,p:longint;
procedure swap(var a,b:longint);
var c:longint;
begin
 c:=a;
 a:=b;
 b:=c;
end;
procedure sort(l,r,kk:longint);
var i,j,m:longint;
begin
 i:=l;
 j:=r;
 if i>j then exit;
 m:=st[kk,l+random(r-l+1)];
 repeat
  while st[kk,i]<m do inc(i);
  while st[kk,j]>m do dec(j);
  if i>j then break;
  swap(st[kk,i],st[kk,j]);
  //swap(stn[kk,i],stn[kk,j]);
  swap(cst[kk,i],cst[kk,j]);
  inc(i); dec(j);
 until i>j;
 if i<r then sort(i,r,kk);
 if l<j then sort(l,j,kk);
end;
begin
 randomize;
 readln(n);
 for i:=1 to n do read(a[i]); readln;
 for i:=1 to n do read(b[i]); readln;
 for i:=1 to n do read(c[i]); readln;
 for i:=1 to 3 do l[i]:=1;
 for i:=1 to n do
 begin
  x:=b[i];
  inc(r[x]);
  cst[x,r[x]]:=i;
  st[x,r[x]]:=a[i];
  if b[i]<>c[i] then
  begin
   x:=c[i];
   inc(r[x]);
   cst[x,r[x]]:=i;
   st[x,r[x]]:=a[i];
  end;
 end;
 for i:=1 to 3 do sort(1,r[i],i);
 readln(m);
{ for i:=1 to 3 do
 begin
  for j:=1 to r[i] do write(st[i,j],' ');
  writeln;
 end;}
 for i:=1 to m do
 begin
  ans:=0;
  read(x);
  c1:=l[x];
  c2:=r[x];
  while(c1<=c2)and(v[cst[x,c1]]=1)do
  begin
   inc(l[x]);
   c1:=l[x];
  end;
  c1:=l[x];
  if c1>c2 then write(-1,' ')else
  begin
   v[cst[x,c1]]:=1;
   inc(l[x]);
   write(st[x,c1],' ');
  end;
 end;
end.