var
 s,s1:ansistring;
 i,j:longint;
begin
 readln(s);
 for i:=length(s) downto 1 do s1:=s1+s[i];
 writeln(s,s1);
end.