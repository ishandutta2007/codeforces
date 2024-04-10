var
 s:ansistring;
 i,j,n,k:longint;
begin
 readln(s);
 for i:=length(s) downto 2 do if(s[i]='/')and(s[i-1]='/')then delete(s,i,1);
 if s[1]<>'/' then s:=s+'/';
 while(length(s)>1)and(s[length(s)]='/')do delete(s,length(s),1);
 writeln(s);
end.