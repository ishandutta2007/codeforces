type re=record
  a,b,c:longint;
end;
var
  m,n,i,j,h,t,ans,uu,u,v,l,x,c,d:longint;
  a:array[1..1000000]of re;
  b,q,head,pre:array[1..1000000]of longint;
  f:array[1..1000000]of boolean;
procedure arr(x,y:longint);
begin
  inc(l);
  a[l].a:=head[x];
  a[l].b:=y;
  head[x]:=l;
end;
begin
  readln(n,m,x);
  fillchar(f,sizeof(f),false);
  for i:=1 to m do
  begin
    read(b[i]);
    f[b[i]]:=true;
    inc(t);
    q[t]:=b[i];
  end;
  for i:=1 to n-1 do
  begin
    read(c,d);
    arr(c,d); arr(d,c);
  end;
  while h<t do
  begin
    inc(h);
    uu:=q[h];
    u:=head[uu];
    while u<>0 do
    begin
      v:=a[u].b;
      if f[v]=false then
      begin
        inc(ans);
        a[u].c:=-1;
        f[v]:=true;
        pre[v]:=uu;
        inc(t);
        q[t]:=v;
      end;
      u:=a[u].a;
    end;
  end;
  writeln(n-1-ans);
  for i:=1 to n-1 do
    if (a[i*2].c<>-1) and (a[i*2-1].c<>-1) then write(i,' ');
end.