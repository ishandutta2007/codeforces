var
 d:array[1..1000,1..1000]of longint;
 a,sc,i,j,dp:longint;
begin;
 readln(a);
 if a mod 2=1 then
 begin
  sc:=-1;
  dp:=1;
  for i:=0 to (a mod 2)+(a div 2)-1 do
  for J:=(a mod 2)+(a div 2)-i to (a mod 2)+(a div 2)+i do begin inc(sc,2); d[i+1,j]:=sc; end;
  for i:=(a mod 2)+(a div 2)+1 to a do
  begin
   inc(dp);
   for J:=dp to a-dp+1 do begin inc(sc,2); d[i,j]:=sc; end;
  end;
  sc:=0;
  dp:=0;
  for i:=1 to a do
  begin
   for j:=1 to (a div 2)-i+1 do begin inc(sc,2); d[i,j]:=sc; end;
   for j:=(a div 2)+(a mod 2)+i to a  do begin inc(sc,2); d[i,j]:=sc; end;
  end;
  for i:=(a div 2)+(a mod 2)+1 to a do
  begin
   inc(dp);
   for j:=1 to dp do begin inc(sc,2); d[i,j]:=sc; end;
   for j:=a-dp+1 to a  do begin inc(sc,2); d[i,j]:=sc; end;
  end;
 end;
 for i:=1 to a do
 begin
  for j:=1 to a-1 do write(d[i,j],' ');
  writeln(d[i,a]);
 end;
end.