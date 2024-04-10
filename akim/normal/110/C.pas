var a:array[1..1000100,1..2]of longint;
    n,i:longint;
begin
 readln(n);a[4,1]:=1;a[7,2]:=1;
 for i:=1 to n do
  if (a[i,1]<>0)or(a[i,2]<>0) then
  begin
   if (a[i+4,1]=0)and(a[i+4,2]=0) then begin a[i+4,1]:=a[i,1]+1;a[i+4,2]:=a[i,2];end;
   if (a[i+7,1]=0)and(a[i+7,2]=0) then begin a[i+7,1]:=a[i,1];a[i+7,2]:=a[i,2]+1;end;
  end;
 if (a[n,1]<>0)or(a[n,2]<>0) then
 begin
  for i:=1 to a[n,1] do
   write(4);
  for i:=1 to a[n,2] do
   write(7);
 end else writeln('-1');
end.