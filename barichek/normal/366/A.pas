uses math;
var
  a:array[1..10000,1..4]of longint;
  n,mini1,mini2:longint;
  i,j:longint;
begin
  read(n);
  for i:=1 to 4 do
     for j:=1 to 4 do
       read(a[i,j]);
  for i:=1 to 4 do
     if min(a[i,1],a[i,2])+min(a[i,3],a[i,4])<=n then
       begin
         write(i,' ',min(a[i,1],a[i,2]),' ',n-min(a[i,1],a[i,2]));
         halt;
       end;
  write(-1);
end.