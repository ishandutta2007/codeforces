uses math;
var
  a:array[1..4]of longint;
  i,j,ans:longint;
begin
  ans:=0;
  for i:=1 to 4 do
    read(a[i]);
  for i:=1 to 4 do
    for j:=1 to 4 do
      if (i<>j) and (a[i]=a[j]) then inc(ans);
  if ans=0 then ans:=0;
  if ans=2 then ans:=1;
  if (ans=6) or (ans=4) then ans:=2;
  if ans=12 then ans:=3;
  writeln(ans);
end.