var
 s,s1,s2:ansistring;
 i,j,n,k,l:Longint;     
begin
 readln(s);
 s1:='AOYEUI';
 for i:=length(s) downto 1 do                                                                           
 begin
  k:=pos(upcase(s[i]),s1);
  if k<>0 then delete(s,i,1);
 end;   
 for i:=length(s) downto 1 do if s[i]=upcase(s[i]) then s[i]:=chr(ord(s[i])+97-65);                                            
 for i:=length(s) downto 1 do if s[i]<>'.' then insert('.',s,i);
 writeln(s);
end.