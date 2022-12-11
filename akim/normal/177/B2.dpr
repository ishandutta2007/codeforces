var s,i,p,v,c:longint;
begin
 readln(s);p:=trunc(sqrt(s))+1;i:=2;v:=0;v:=s;
 while s>1 do
 begin
  c:=0;
  for i:=i to p do
   if s mod i=0 then begin c:=i;break;end;
  if c>0 then
  begin
   s:=s div c;
   v:=v+s;
   p:=trunc(sqrt(s))+1;
  end else
  begin
   s:=1;
   v:=v+1;
  end;
 end;
 writeln(v);
end.