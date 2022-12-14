var
 a:array[1..3]of longint;
 i,j,m:longint;
begin
 for i:=1 to 3 do read(a[i]) ;
 for i:=1 to 2 do
 for j:=i+1 to 3 do if a[i]>a[j] then
 begin
  m:=a[j];
  a[j]:=a[i];
  a[i]:=m;
 end;
 m:=(a[2]-a[1])+(a[3]-a[2]);
 writeln(m);
end.