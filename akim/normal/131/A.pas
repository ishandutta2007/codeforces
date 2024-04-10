var s,t:string;l,i,f:longint;log:boolean;
begin
 readln(s);l:=length(s);
 log:=true;
 for i:=2 to l do
  if s[i]=upcase(s[i]) then else begin log:=false;break;end;
 if not(log) then else
 begin
  if s[1]=upcase(s[1]) then write(chr(ord(s[1])+32)) else write(upcase(s[1]));
  for f:=2 to l do
   write(chr(ord(s[f])+32));
  halt(0);
 end;
 writeln(s);
end.