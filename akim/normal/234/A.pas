var s:string;i,l:longint;
begin
 assign(input,'input.txt');reset(input);
 assign(output,'output.txt');rewrite(output);
 readln(l);l:=l div 2;
 readln(s);
 for i:=1 to l do
  if (s[i]='R')and(s[i+l]='L') then writeln(i+l,' ',i) else writeln(i,' ',i+l);
 close(input);close(output);
end.