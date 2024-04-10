var a,b:array[1..50]of integer;
    n,i,f,k:integer;
begin
 for i:=1 to 30 do
 begin a[i]:=0;b[i]:=0;end;
 readln(n);
 for i:=1 to n do
  for f:=1 to n do
  begin
   read(k);
   inc(a[i],k);
   inc(b[f],k);
  end;
 k:=0;
 for i:=1 to n do
  for f:=1 to n do
   if a[i]<b[f] then inc(k);
 writeln(k);
end.