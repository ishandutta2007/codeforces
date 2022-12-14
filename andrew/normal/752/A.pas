var
 j1,c,a,b,v,sc,r,i,j,n,m,k:longint;
begin
 readln(n,m,k);
 for i:=1 to n do
  for j1:=1 to m do
  for j:=1 to 2 do
  begin
   inc(sc);
   if sc=k then
   begin
    write(i,' ',j1);
    if j=1 then writeln(' L')else writeln(' R');
    halt;
   end;
  end;
end.