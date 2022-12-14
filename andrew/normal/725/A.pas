var
 sch1,sch2:array[1..200001]of longint;
 a:array[1..200001]of char;
 dp1,dp2:char;
 scc1,scc2,n,m,i,j,k,l,cs,v,sc1,sc2:longint;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
 for i:=n downto 1 do
 begin
  sch1[i]:=scc1;
  if a[i]='<' then inc(scc1);
 end;
 for i:=1 to n do
 begin
  sch2[i]:=scc2;
  if a[i]='>' then inc(scc2);
 end;
 for i:=1 to n do
 begin
  sc1:=0;
  sc2:=0;
  if (a[i]='<') then
  begin
   if sch2[i]=0 then inc(cs);
   continue;
  end;
  if a[i]='>' then
  begin
   if sch1[i]=0 then inc(cs);
   continue;
  end;
 end;
 writeln(cs);
end.