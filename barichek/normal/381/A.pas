uses math;
var
  a:array[1..10000] of longint;
  n,nv,nvv,ans1,ans2:longint;
  i,j:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);
  ans1:=0;
  ans2:=0;

  nv:=n;
  nvv:=1;
  for i:=1 to n div 2 do
    begin
      if max(a[nvv],a[nv])=a[nv] then
           begin dec(nv); inc(ans1,a[nv+1]); end
      else
           begin inc(nvv); inc(ans1,a[nvv-1]); end;
      if max(a[nvv],a[nv])=a[nv] then
           begin dec(nv); inc(ans2,a[nv+1]); end
      else
           begin inc(nvv); inc(ans2,a[nvv-1]); end;
    end;
  if n mod 2=1 then inc(ans1,a[nv]);
  writeln(ans1,' ',ans2);
end.