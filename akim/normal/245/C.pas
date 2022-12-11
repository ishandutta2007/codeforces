var a:array[1..100]of longint;
    n,o,i:longint;
begin
 readln(n);
 if (n=1)or(n mod 2=0) then begin writeln('-1');halt(0);end;
 for i:=1 to n do
  read(a[i]);
 o:=0;
 for i:=n downto 1 do
  if i*2+1<=n then
  while (a[i*2]>0)or(a[i*2+1]>0) do
  begin
   inc(o);
   if a[i]>0 then dec(a[i]);
   if a[i*2]>0 then dec(a[i*2]);
   if a[i*2+1]>0 then dec(a[i*2+1])
  end;
 writeln(o+a[1]);
end.