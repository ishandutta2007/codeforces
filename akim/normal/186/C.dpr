var n,k,l,mn:int64;
begin
 readln(n);k:=1;mn:=2;
 if n=0 then writeln(1) else
 begin
  n:=n-1;
  while n>0 do 
  begin
   if n mod 2=1 then k:=k*mn;
   mn:=mn*mn;
   n:=n div 2;
   mn:=mn mod 1000000007;
   k:=k mod 1000000007;
  end;
  l:=k*2 mod 1000000007;
  k:=k*(l+1)mod 1000000007;
  writeln(k);
 end;
end.