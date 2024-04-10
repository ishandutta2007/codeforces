var
 s:shortstring;
 k,i,sc,max,j:longint;
begin
 readln(s);
 for i:=1 to length(s) do s[i]:=upcase(s[i]);
 for i:=1 to length(s) do
 begin
  if (s[i]<>'A')and(s[i]<>'E')and(s[i]<>'I')
  and(s[i]<>'O')and(s[i]<>'U')and(s[i]<>'Y')
  then s[i]:='+';
 end;
 i:=0;
 s:='A'+s+'A';
 while i<=length(s) do
 begin
  inc(i);
  s[i]:='+';
  sc:=0;
  for i:=i to length(s) do
  begin
   inc(sc);
   if s[i+1]<>'+' then break;
  // if i=length(s)then break;
  end;
  if sc>k  then k:=sc;
 end;
 { if k=0 then writeln(1)} {else} writeln(k);
end.