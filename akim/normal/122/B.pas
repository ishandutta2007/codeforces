var n4,n7,i,l:longint;s:string;
begin
 readln(s);l:=length(s);
 for i:=1 to l do
 begin
  if s[i]='4' then inc(n4);
  if s[i]='7' then inc(n7);
 end;
 if (n4=0)and(n7=0)then writeln(-1) else
 if (n4=0)then writeln(7) else
 if (n7=0)then writeln(4) else
 if (n4>=n7)then writeln(4) else
 writeln(7);
end.