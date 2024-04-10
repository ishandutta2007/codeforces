var
 fl,mx,s,sc,y,x,c,p,i,j,k:longint;
begin
 mx:=maxlongint;
 readln(p,y,x);
  for i:=x to 1000000 do
  begin
   fl:=0;
   k:=abs(y-i);
   if k mod 50<>0 then continue;
   k:=i-y;
   if k>0 then begin sc:=k div 100; if k mod 100<>0 then inc(sc); end;
   s:=(i div 50)mod 475;
   for j:=1 to 25 do
   begin
    s:=(s*96+42)mod 475;
    if 26+s=p then begin fl:=1; break; end;
   // if i=y then writeln(s);
   end;
   if fl=1 then if sc<mx then mx:=sc;
  // if i=10880 then writeln(sc,' ',fl);
  end;
 writeln(mx);
end.