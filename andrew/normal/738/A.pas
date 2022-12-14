var
 s,v:ansistring;
 i,j,n,ch1,ch2,k,l,o:longint;
begin
 readln(n);
 readln(s);
 //v:=s;
 v:='';
 i:=1;
 while i<=n do
 begin
 // writeln(i);
  if(s[i]='o')and(s[i+1]='g')and(s[i+2]='o')then
  begin
   //writeln(i);
   ch1:=i;
   i:=i+3;
  // writeln(ch1);
   if i+1<=n then
   while (s[i]='g')and(s[i+1]='o')do
   begin
    //writeln(n);
    inc(i,2);
    if i+1>n then break;
   end;
  // for j:=ch1 to i-1 do s[j]:='*';
   v:=v+'***';
  end else
 begin inc(i);  v:=v+s[i-1]; end;
 end;
 writeln(v);
end.