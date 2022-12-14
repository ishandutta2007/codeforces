var
 b:array[1..100,1..100]of longint;
 a:array[0..100]of longint;
 d,m,i,j,sum:longint;
begin
 for i:=1 to 5 do
 begin
  for j:=1 to 5 do read(b[i,j]);
  readln;
 end;

 for i:=1 to 5 do a[i]:=i;
 while true do
 begin
  sum:=0;
  inc(sum,(b[a[1],a[2]]+b[a[2],a[1]])+(b[a[2],a[3]]+b[a[3],a[2]]));
  inc(sum,2*((b[a[3],a[4]]+b[a[4],a[3]])+(b[a[4],a[5]]+b[a[5],a[4]])));
  if sum>m then m:=sum;
  for i:=4 downto 0 do if a[i]<a[i+1] then break;
  if i=0 then break;
  for j:=5 downto 0 do if a[j]>a[i] then break;
  d:=a[i];
  a[i]:=a[j];
  a[j]:=d;
  j:=5;
  for i:=i+1 to (i+5)div 2 do
  begin
  d:=a[i];
  a[i]:=a[j];
  a[j]:=d;
   dec(j);
  end;
 end;
 writeln(m);
end.