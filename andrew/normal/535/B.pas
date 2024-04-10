var
 s:ansistring;
 i,j,n,ch1:longint;
begin
 readln(s);
 for i:=1 to length(s) do if s[i]='4' then s[i]:='0' else s[i]:='1';
 ch1:=1;
 for i:=1 to length(s) do ch1:=ch1*2+(ord(s[i])-48);
 writeln(ch1-1);
end.