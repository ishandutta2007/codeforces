var a:array[1..100]of longint;
    n,i,l:longint;
begin
 readln(n,a[1],l);
 for i:=1 to n-1 do
 begin
  if a[i]>0 then
  begin
   a[i+1]:=l-a[i];
   a[i]:=l;
  end else
  begin
   a[i+1]:=1-a[i];
   a[i]:=1;
  end;
 end;
 if (0<a[n])and(a[n]<=l) then
 begin
  for i:=1 to n do
   write(a[i],' ');
 end else writeln('-1');
end.